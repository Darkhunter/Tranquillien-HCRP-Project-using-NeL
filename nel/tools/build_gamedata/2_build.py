#!/usr/bin/python
# 
# \file 2_build.py
# \brief Run all build processes
# \date 2009-02-18 09:22GMT
# \author Jan Boon (Kaetemi)
# Python port of game data build pipeline.
# Run all build processes
# 
# NeL - MMORPG Framework <http://dev.ryzom.com/projects/nel/>
# Copyright (C) 2010  Winch Gate Property Limited
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero General Public License as
# published by the Free Software Foundation, either version 3 of the
# License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Affero General Public License for more details.
#
# You should have received a copy of the GNU Affero General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
# 

import time, sys, os, shutil, subprocess, distutils.dir_util
sys.path.append("configuration")

if os.path.isfile("log.log"):
	os.remove("log.log")
log = open("log.log", "w")
from scripts import *
from buildsite import *
from tools import *

sys.path.append(WorkspaceDirectory)
from projects import *

# Log error
printLog(log, "")
printLog(log, "-------")
printLog(log, "--- Run the build processes")
printLog(log, "-------")
printLog(log, time.strftime("%Y-%m-%d %H:%MGMT", time.gmtime(time.time())))
printLog(log, "")
# For each project
for projectName in ProjectsToProcess:
	os.putenv("NELBUILDACTIVEPROJECT", os.path.abspath(WorkspaceDirectory + "/" + projectName))
	os.chdir("processes")
	try:
		subprocess.call([ "python", "2_build.py" ])
	except Exception, e:
		printLog(log, "<" + projectName + "> " + str(e))
	os.chdir("..")
	try:
		projectLog = open("processes/log.log", "r")
		projectLogData = projectLog.read()
		projectLog.close()
		log.write(projectLogData)
	except Exception, e:
		printLog(log, "<" + projectName + "> " + str(e))
printLog(log, "")

log.close()
if os.path.isfile("2_build.log"):
	os.remove("2_build.log")
shutil.copy("log.log", time.strftime("%Y-%m-%d-%H-%M-GMT", time.gmtime(time.time())) + "_build.log")
shutil.move("log.log", "2_build.log")
