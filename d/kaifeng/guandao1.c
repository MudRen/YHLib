inherit ROOM;

void create()
{
        set("short", "�ٵ�");
        set("long", @LONG
���������ӿ��⸮�����ݸ��Ĺٵ�����������·�ΰ��Ϻ�
����Ҳ���١�����ͨ�򿪷⣬����ͨ�����ݡ�
LONG);
        set("exits", ([
  		"east":__DIR__"tokaifeng",
  		"northwest":__DIR__"shulin",
	]));
        set("outdoors", "zhongzhou");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
