inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", @LONG
�������ѵ������ݵ������š��߸ߵĳ�¥����ȥ�᲻�ɴݡ�
������һ¥�ݿ����ϳ�¥�Ķ��㡣��˵�����سǵĽ����书��
�ף���ȴ�ܺñ��䡣
LONG);
	set("no_clean_up", 0);
	set("exits", ([
  		"west" : __DIR__"xijiao",
  		"east" : __DIR__"yanling2",
  		"up" : __DIR__"chenglouup",
	]));
        set("objects", ([
                "/d/kaifeng/npc/guanbing" : 4,
                "/d/city/npc/wujiang" : 1,
                "/clone/npc/walker" : 1,
        ]));
	set("outdoors", "zhongzhou");

	setup();
	replace_program(ROOM);
}
