#!/bin/bash
touch test.output
./cmc -v tmp/a00.c > test.output
./cmc -v tmp/a01.c >> test.output
./cmc -v tmp/a02.c >> test.output
./cmc -v tmp/a03.c >> test.output
./cmc -v tmp/a04.c >> test.output
