inherit ROOM;

void create()
{
	set("short", "��ԭ");
	set("long", @LONG
����һƬ�ޱ��޼ʵĲ�ԭ�����˸ߵ����������������
�����е��㣬��������֮����ӿ�Ĳ��Σ��Ĵ�Ʈҡ�����뵽��
���е����Σ�������Ȼ���¡� 
LONG);
	set("outdoors", "gaochang");
	set("exits", ([
  		"north" : __DIR__"lake4",
  		"south" : __DIR__"caoyuan2",
	]));

	setup();
	replace_program(ROOM);
}
