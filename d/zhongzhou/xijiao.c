inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
������ԭ��һ�������ݸ����Ľ��⡣��������ݲ�Զ����
��Ҳ��˵�ù�ȥ�������ǿ��⸮���򣬶���ͨ�����ݸ���
LONG);
	set("exits", ([
  		"west" : __DIR__"wroad1",
  		"east" : __DIR__"chenglou",
	]));
	set("outdoors", "zhongzhou");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
