inherit ROOM;

void create()
{
        set("short", "ʯ��С��");
        set("long", @LONG
�����·�趸��һ������ʯ��֮������������ֻ������
ɭɭ��������ˡ�·������һ�Ѱ׹ǣ������й�����ҫ������
��౦ʯ����
LONG);
        set("outdoors", "gaochang");

        if (random(10) > 8)
        	set("objects", ([
			"/clone/money/gold" : 1,
			"/clone/fam/item/bixue" : 1,
        		__DIR__"obj/skeleton" : 1,
		]));

        set("exits", ([ 
		"south" : __DIR__"xiaojing1",
  		"west" : __DIR__"feixu1",
	]));

        setup();
        replace_program(ROOM);
}
