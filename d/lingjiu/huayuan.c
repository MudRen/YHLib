inherit ROOM;

void create()
{
  	set("short", "��԰");
  	set("long", @LONG
�����ǰ������һ�������Ļ�԰����԰������һЩ������
������Լ�ɼ�Ʈ���ٻӰ�����ǹ��еĽ���������ˣ����԰��
����һ����ɽ����԰�Ķ�����ͷ�ǳ��ȣ�������һ��С��ͨ��
��ɽͯ������֮����
LONG);
  	set("exits",([
      		"west" : __DIR__"changl1",
      		"north" : __DIR__"xiaodao1",
      		"east" : __DIR__"changl2",
      		"south" : __DIR__"changl15",
  	]));
  	set("outdoors", "lingjiu");
  	set("objects", ([
      		"/clone/quarry/lu" : 1,
  	]));
  	setup();
        replace_program(ROOM);
}
