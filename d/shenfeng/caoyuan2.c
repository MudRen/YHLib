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
  		"west" : __DIR__"caoyuan3",
  		"north" : __DIR__"caoyuan1",
	]));

	setup();
	replace_program(ROOM);
}
