#!/usr/bin/python
# 
# \file 7_client_install.py
# \brief Install to client install
# \date 2009-02-18 16:19GMT
# \author Jan Boon (Kaetemi)
# Python port of game data build pipeline.
# Install to client install
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
printLog(log, "--- Install to client install")
printLog(log, "-------")
printLog(log, time.strftime("%Y-%m-%d %H:%MGMT", time.gmtime(time.time())))
printLog(log, "")

# Find tools
BnpMake = findTool(log, ToolDirectories, BnpMakeTool, ToolSuffix)
printLog(log, "")

if BnpMake == "":
	toolLogFail(log, BnpMakeTool, ToolSuffix)
else:
	for category in InstallClientData:
		printLog(log, "CATEGORY " + category["Name"])
		if (category["UnpackTo"] != None):
			targetPath = ClientInstallDirectory
			if (category["UnpackTo"] != ""):
				targetPath += "/" + category["UnpackTo"]
			mkPath(log, targetPath)
			for package in category["Packages"]:
				printLog(log, "PACKAGE " + package[0])
				mkPath(log, InstallDirectory + "/" + package[0])
				copyFilesNoTreeIfNeeded(log, InstallDirectory + "/" + package[0], targetPath)
		else:
			targetPath = ClientInstallDirectory + "/data"
			mkPath(log, targetPath)
			for package in category["Packages"]:
				printLog(log, "PACKAGE " + package[0])
				sourcePath = InstallDirectory + "/" + package[0]
				mkPath(log, sourcePath)
				targetBnp = targetPath + "/" + package[0] + ".bnp"
				if (len(package[1]) > 0):
					targetBnp = targetPath + "/" + package[1][0]
					printLog(log, "TARGET " + package[1][0])
				needUpdateBnp = 1
				if (len(package) > 2):
					needUpdateBnp = needUpdate(log, sourcePath + "/" + package[2], targetBnp)
				else:
					needUpdateBnp = needUpdateDirNoSubdirFile(log, sourcePath, targetBnp)
				if (needUpdateBnp):
					printLog(log, "BNP " + targetBnp)
					subprocess.call([ BnpMake, "/p", sourcePath, targetPath ] + package[1])
				else:
					printLog(log, "SKIP " + targetBnp)
printLog(log, "")

log.close()
if os.path.isfile("7_client_install.log"):
	os.remove("7_client_install.log")
shutil.copy("log.log", time.strftime("%Y-%m-%d-%H-%M-GMT", time.gmtime(time.time())) + "_client_install.log")
shutil.move("log.log", "7_client_install.log")
