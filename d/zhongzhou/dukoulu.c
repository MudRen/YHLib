inherit ROOM;

void create()
{
        set("short", "�ɿ�·");
        set("long", @LONG
����������ͨ�����ݳǵĴ�������Ƕɿڡ�ͨ���ɿڿ�
�Ե��ｭ�������ݣ����������ϱ���Ҫ����
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"south" : __DIR__"to_zhongzhou",
  		"north" : __DIR__"zhongzhoudu",
	]));
        set("outdoors", "zhongzhou");
        set("objects", ([
  		"/d/beijing/npc/boy1" : 1,
  		"/d/beijing/npc/girl2" : 1,
	]));
        set("no_sleep_room", 1);

        setup();
        replace_program(ROOM);
}
