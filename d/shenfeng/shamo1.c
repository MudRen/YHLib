inherit ROOM;

void create()
{
	set("short", "ɳ��С��");
	set("long", @LONG
����һ���ޱߵ�ɳ���أ�ɽ�Ƶ�������ͻȻ������Ӱ��
�١�������������綼��ů�ġ����ϵ�ʯ������һ�ְ����
��ɫ�������Ǳ���ѪȾ���һ����һ���������۵�С��������
�Ͷ�����չ��
LONG);
        set("outdoors", "gaochang");
	set("exits", ([
  		"west" : __DIR__"shamo2",
  		"eastup" : __DIR__"caoyuan7",
	]));
	setup();
	replace_program(ROOM);
}
