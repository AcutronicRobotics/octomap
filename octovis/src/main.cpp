/*
 * This file is part of OctoMap - An Efficient Probabilistic 3D Mapping
 * Framework Based on Octrees
 * http://octomap.github.io
 *
 * Copyright (c) 2009-2014, K.M. Wurm and A. Hornung, University of Freiburg
 * All rights reserved. License for the viewer octovis: GNU GPL v2
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see http://www.gnu.org/licenses/.
 */

#include <QtGui>
#include <QApplication>
#include <octovis/ViewerGui.h>
#include <stdlib.h> //strtol

int main(int argc, char *argv[]) {

  std::string filename = "";
  int depth = 0;
  if (argc == 1) { 
    std::cout << "Usage: " << argv[0] << " [mapfile] [tree depth cutoff]\n"; 
    std::cout << "Where the optional [tree depth cutoff] is an integer from 1 to 16\n"; 
  }
  if (argc >= 2) { filename = std::string(argv[1]); }
  if (argc >= 3) { depth = std::strtol(argv[2], NULL, 10); }//zero on parse error

  QApplication app(argc, argv);

  octomap::ViewerGui gui(filename, NULL, depth);
  gui.show(); 
  return app.exec();
}
