#!/bin/bash
LOG_FILE=./LOG_INSTALL.log


# LIBFORBES INSTALLATION SCRIPT
# Licence note:
#
# ForBES is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#   
# ForBES is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU Lesser General Public License for more details.
# 
# You should have received a copy of the GNU Lesser General Public License
# along with ForBES. If not, see <http://www.gnu.org/licenses/>.


#						 #
# Do not modify this file after this line	 #
#						 #


# Function: install_libforbes
function install_libforbes {

	# install packages
	sudo apt-get update
	sudo apt-get -y install libopenblas-base 
	sudo apt-get -y install libopenblas-dev 
	sudo apt-get -y install libblas-dev 
	sudo apt-get -y install liblapack-dev
	sudo apt-get -y install libcppunit-dev 
	sudo apt-get -y install g++-4.8
	
	# before install
	export CXX=g++-4.8
	sudo ln -s /usr/lib/openblas-base/libopenblas.a /usr/lib/;
	sudo ldconfig 
  	mkdir -p libs
	chmod a+x ./scripts/install-suitesparse.sh
	./scripts/install-suitesparse.sh 
	wget http://www.netlib.org/lapack/lapack-3.6.0.tgz \
	  -O ./libs/lapack-3.6.0.tgz
	tar zxf ./libs/lapack-3.6.0.tgz -C ./libs
	rm ./libs/lapack-3.6.0.tgz 
	cd ./libs/lapack-3.6.0/
  	cp make.inc.example make.inc
  	cd LAPACKE
  	make > /dev/null
  	sudo cp ./include/lapacke.h /usr/include/
  	sudo cp ./include/lapacke_mangling.h /usr/include/
  	sudo cp ./include/lapacke_utils.h /usr/include/
  	cd ..
  	sudo cp ./liblapacke.a /usr/lib
	cd ../../
}

exec 3>&1 1>>${LOG_FILE} 2>&1
install_libforbes | tee /dev/fd/3;

CONFIG_FILE=config.mk
echo "# Auto-generated config file." > $CONFIG_FILE
echo -e "# Path to your SuiteSparse directory" >> $CONFIG_FILE
echo -e "SS_DIR = libs/SuiteSparse" >> $CONFIG_FILE
echo -e "# Extra headers and libraries paths" >> $CONFIG_FILE
echo -e "IEXTRA = /usr/include" >> $CONFIG_FILE
echo -e "LEXTRA = /usr/lib" >> $CONFIG_FILE

make
make test
