inherit ROOM;

void create()
{
  	set ("short", "���");
  	set ("long", @LONG
��ƽԭ֮�ϵ�һ����·�������˺ܶ࣬·�������Զ����
��Сͤ�ӹ�����Ъ�ţ���ȥ���ǿ���ǡ����治Զ�Ǹ�����
·�ڡ�
LONG);
  	set("outdoors", "kaifeng");

  	set("exits", ([
  		"south" : __DIR__"dadao1",
  		"north" : __DIR__"nanying",
	]));

  	setup();
  	replace_program(ROOM);
}
