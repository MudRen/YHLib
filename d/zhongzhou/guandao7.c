inherit ROOM;

void create()
{
  	set ("short", "�ٵ�");
  	set ("long", @LONG
����һ���ɹٸ�����ĵ�·�����ݰ����������ϱ���ͨ
Ҫ�����������Զ��ˣ���ʱ��������ĺ͸ϳ��ľ�����
LONG);

  	set("outdoors", "zhongzhou");
  	set("exits", ([
  		"south" : __DIR__"beimen",
  		"north" : __DIR__"guandao6",
	]));
  	setup();
}
