// Room: /u/wfoxd/xiaohuayuan.c

inherit ROOM;

void create()
{
	set("short", "С��԰");
	set("long", @LONG
������ɽׯ��һ��С��԰������Կ���һЩ������ɫ�Ļ�(flower),���������ͨ�������Ժ�䡣
LONG	);
	set("exits", ([ /* sizeof() == 3 */
  		"south" : __DIR__"lajichang",
  		"east" : __DIR__"wroom",
  		"west" : __DIR__"wroom2",
	]));
        set("objects",([
                "/d/foshan/obj/hua1" :1,
                "/d/foshan/obj/hua2" :2,
                "/d/foshan/obj/hua3" :3,
	]));

	set("item_desc", ([
                "flower" : "����ȫ������������ɫ�������֡�\n",
	]));
	setup();
	replace_program(ROOM);
}
