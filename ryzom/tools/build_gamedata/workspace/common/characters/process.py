#!/usr/bin/python
# 
# \file config.py
# \brief Process configuration
# \date 2010-08-27 17:02GMT
# \author Jan Boon (Kaetemi)
# Python port of game data build pipeline.
# Process configuration.
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

# *** PROCESS CONFIGURATION ***

# *** PROCESS CONFIG ***
ProcessToComplete = [ ]
ProcessToComplete += [ "skel" ]
ProcessToComplete += [ "swt" ]
ProcessToComplete += [ "shape" ]
ProcessToComplete += [ "anim" ]
ProcessToComplete += [ "clodbank" ]


# *** COMMON NAMES AND PATHS ***
EcosystemName = "characters"
EcosystemPath = "common/" + EcosystemName
ContinentName = EcosystemName
ContinentPath = EcosystemPath
CommonName = ContinentName
CommonPath = ContinentPath


# *** SHAPE EXPORT OPTIONS ***

# Compute lightmaps ?
ShapeExportOptExportLighting = "true"

# Cast shadow in lightmap ?
ShapeExportOptShadow = "true"

# Lighting limits. 0 : normal, 1 : soft shadows
ShapeExportOptLightingLimit = 0

# Lightmap lumel size
ShapeExportOptLumelSize = "0.25"

# Oversampling value. Can be 1, 2, 4 or 8
ShapeExportOptOversampling = 1

# Does the lightmap must be generated in 8 bits format ?
ShapeExportOpt8BitsLightmap = "false"

# Does the lightmaps export must generate logs ?
ShapeExportOptLightmapLog = "true"

# Coarse mesh texture mul size
TextureMulSizeValue = "1.5"

DoBuildShadowSkin = 0


#panoply_file_list = panoply_files.txt ???
#hls_bank_file_name = characters.hlsbank ???



# *** CLODBANK OPTIONS ***

ClodConfigFile = "stuff/lod_actors/lod_" + CommonName + "/clod_char_script.cfg"
ClodBankFileName = CommonName + ".clodbank"


# *** COARSE MESH TEXTURE NAME ***
CoarseMeshTextureNames = [ ]


# *** POSTFIX USED BY THE MULTIPLE TILES SYSTEM ***
MultipleTilesPostfix = [ ]
MultipleTilesPostfix += [ "_sp" ]
MultipleTilesPostfix += [ "_su" ]
MultipleTilesPostfix += [ "_au" ]
MultipleTilesPostfix += [ "_wi" ]


# *** SHADOW SKIN OPTIONS ***
# Characters are made of approx 4000 polys with multiple Skins binded (legs, short, torso...). 35% => 1400 polys.
BuildShadowSkin = 1
BuildShadowSkinRatio = 35
BuildShadowSkinMaxface = 2000


# *** ANIMATIONS OPTIONS ***

DoOptimizeAnimations = 1
