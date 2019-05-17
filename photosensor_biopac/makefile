upload: main/main.ino
	@ echo "Building and uploading code to Arduino"
	@ arduino --upload main/main.ino

find-dep:
	@ echo "> Getting dependencies\n\n"
	@ wget -O ~/Arduino/libraries/tmp_lib.tar https://github.com/alextaujenis/RBD_Timer/archive/1.3.0.tar.gz
	@ tar -xvf ~/Arduino/libraries/tmp_lib.tar -C ~/Arduino/libraries
	@ rm ~/Arduino/libraries/tmp_lib.tar  # clean up

