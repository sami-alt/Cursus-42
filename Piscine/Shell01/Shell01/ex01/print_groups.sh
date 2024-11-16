#!/bin/sh
id -Gn $FT_USER | tr "\n" "\0" | tr " " ","
