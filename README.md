# Wolfenstein

Проект запустится только на MacOS, т.к. используется специальная библиотека mlx.

`make` собирает проект

./cub3D требует аргумент в формате файл.cub 

Пример: `./cub3D map.cub` запустит демонстрационный вариант

__Есть возможонсть измеять карту.__ \
Карта обязательно должна иметь:
- `R x y` где x и y это разрешение \
__Путь к текстурам для соответствующих сторон света__
- WE ./texture/WALL32.xpm
- NO ./texture/WALL53.xpm
- SO ./texture/WALL88.xpm
- EA ./texture/WALL89.xpm \
__Путь к спрайту__
- S ./texture/BAR1M0.xpm \
__Цвет пола и потолка__
- F 255,255,255
- C 148,235,255

__В самом конце должна быть карта, отделенная пустой строкой__ \
Карта состоит из следующих элементов: \
`1` - стена \
`2` - спрайт \
`0` - свободное место \
`S` `W` `N` или `E` - игрок с соответствующим направлением взгляда \
Карта должа иметь одного игрока и быть огорожена стенами.

В игре есть возможность сделать скрин командой `--save` 
