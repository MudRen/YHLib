inherit ROOM;

void create ()
{
  	set ("short", "����ͤ");
  	set ("long", @LONG
��ͤ�����Ϊ���£��м�һʯ�������Ͽ��ź�ʮ�ţ���ʮ�ŵ�һ�����̣�
�оֻ�δ��ȥ���峿��������飬Ϧ������ʱƷ��̸�죬��������һ����¡�
LONG);

  	set("exits", ([
  		"south" : __DIR__"stone_road2",
	]));

  	setup();
        replace_program(ROOM);
}
