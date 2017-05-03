#!/bin/bash
openocd -f openocd/board.cfg -c "program build/kalaina.elf; reset; exit"
