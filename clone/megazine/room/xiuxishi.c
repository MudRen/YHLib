// Room: /clone/megazine/xiuxishi.c

inherit ROOM;

void create()
{
        set("short", "��Ϣ��");
	set("long", @LONG
���ǡ��������칫�ҵ���Ϣ�ң���������ԺȺȲ������졣
LONG
	);

	set("exits", ([ 
                "east" : "/d/city/wfoxd",
	]));

        set("objects",([
                  "/clone/food/peanut" : 2,
                  "/d/taohua/obj/cha"  : 2,
        ]));

        set("no_fight", "1");
	setup();
	replace_program(ROOM);
}
