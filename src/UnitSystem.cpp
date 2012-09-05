/*
 * UnitSystem.cpp is part of Brewtarget, written by Mik Firestone
 * (mikfire@gmail.com) and is Copyright Philip G. Lee
 * (rocketman768@gmail.com), 2009-2011.
 *
 * Brewtarget is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * Brewtarget is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "UnitSystem.h"
#include <QRegExp>
#include <QString>
#include <QLocale>

const int UnitSystem::fieldWidth = 0;
const char UnitSystem::format = 'f';
const int UnitSystem::precision = 3;
QMap<QString, Unit*> UnitSystem::nameToUnit;

UnitSystem::UnitSystem()
{
   amtUnit.setPattern("(\\d+(?:\\.\\d+)?|\\.\\d+)\\s*(\\w+)?");
   amtUnit.setCaseSensitivity(Qt::CaseInsensitive);
}

double UnitSystem::qstringToSI(QString qstr, Unit* defUnit)
{
   bool convOk = true;
   double amt = 0.0;
   Unit* u = defUnit;

   if (amtUnit.indexIn(qstr) == -1)
      return 0.0;

   amt = QLocale().toDouble(amtUnit.cap(1), &convOk);
   if( !convOk )
      amt = QLocale::c().toDouble(amtUnit.cap(1));
   
   QString unit = amtUnit.cap(2);

   if ( unit.size() > 0 && getUnit(unit) )
      u = getUnit(unit);

   return u->toSI(amt);
}

Unit* UnitSystem::getUnit(const QString& name)
{
   if( nameToUnit.count(name) < 1 )
      return 0;
   else
      return nameToUnit[name];
}

