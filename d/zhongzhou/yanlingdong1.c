inherit ROOM;

void create()
{
  	set ("short", "���궫·");
  	set ("long", @LONG
�������ݵ�һ����·����·��������������ݳǡ�·����
һƬ���ӿ�����Ȼ���Ǻ��£���һ����֪���Ǵ��˼ҡ�����
�Ҷ����������ſڣ��·�ɵ��⻧�˼����Ҷ��Ǻ��˲�����¡�
LONG);
	set("outdoors", "zhongzhou");

  	set("exits", ([
    		"west" : __DIR__"yanlingdong",
    		"north" : __DIR__"yuanwan",
    		"southeast"  : __DIR__"yanlingdong2",
	]));

        set("objects" , ([
                __DIR__"npc/jiading" : 1,
                "/clone/npc/walker" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
