

build:
	g++ src/main.cpp -I/nix/store/l72caliz7i3j6dxy5p2hcsssbv6rlb1n-freeglut-3.2.2-dev/include -I/nix/store/00kynq23n41hardvbigvsh73pla4bkwr-libglvnd-1.6.0-dev/include -I/nix/store/6hab7m3nccjci40z5f812hpqmvcj1fkb-glu-9.0.2-dev/include -L/nix/store/x108ml8b4ynmh84gvqcmvlv8j4sv2kj6-freeglut-3.2.2/lib -lglut -L/nix/store/1llh99lhbb0nv7npg86c4g6dyh8bhm0r-glu-9.0.2/lib -lGLU -L/nix/store/6ysdnx59r6idn6hqsma31fd9nch3bbhc-libGL-1.5.0/lib -lGL -L/nix/store/88z6jp04l9pnhcyvvppai4ll9svvs0nj-glew-2.2.0/lib -lGLEW -I/nix/store/8krwzlyanihpj37iqzc470w8ql7y2c4x-glew-2.2.0-dev/include -o main

run: build
	./main

clean:
	rm ./main
