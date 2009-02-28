/*
 * guitest.cpp is part of Brewtarget, and is Copyright Philip G. Lee
 * (rocketman768@gmail.com), 2009.
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

#include <iostream>
#include <vector>
#include <string>
#include <QApplication>
#include <QWidget>
#include "MainWindow.h"
#include "recipe.h"
#include "xmlnode.h"
#include "xmltree.h"
#include "database.h"

#include <QPixmap>
#include <QLabel>
#include <QDir>

#include "BeerColorWidget.h"
#include "unit.h"
#include "brewtarget.h"

int main(int argc, char **argv)
{
   QApplication app(argc, argv);
   Brewtarget::setApp(app);

   return Brewtarget::run();
   
   /*
   MainWindow *mainWindow;
   QApplication app(argc, argv);

   Database::initialize();

   mainWindow = new MainWindow();

   mainWindow->show();
   return app.exec();
    */

   /*
   QApplication app(argc, argv);
   QPixmap img("images/glass.png");
   QLabel lbl;
   lbl.setPixmap(img);

   lbl.show();
   return app.exec();
    */
}
