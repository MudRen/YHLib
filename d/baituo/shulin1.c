inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������һƬï�ܵ����֣�����ɫ�������ڸ�����գ�ż��
�������������������֪ʲôҰ�޵�˻�С�
LONG);
        set("outdoors", "baituo");
        set("exits", ([
                "east"      : __DIR__"shulin",
                "southwest" : __DIR__"caomeide",
        ]));
        set("quarrys", ([
                "tu"         : 100000,
                "ji"         : 80000,
                "pao"        : 50000,
                "caihuashe"  : 50000,
                "dushe"      : 20000,
                "hu"         : 5000,
                "bao"        : 2000,
                "laohu"      : 2000,
        ]));
 	setup();
 	replace_program(ROOM);
}
