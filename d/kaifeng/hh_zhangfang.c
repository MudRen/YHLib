inherit ROOM;

void create()
{
        set("short", "�˷�");
        set("long", @LONG
������Ǻ컨���ܶ��ڵ��˷����ط������Ǻ��徲����
���˷���������������ͳ�ƹ�����е������⣬ƽʱ��������
�����˹��������������žž���������������ڶ�����
������Ҳ���÷���
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"east" : __DIR__"hh_hguangchang",
	]));
        setup();
        replace_program(ROOM);
}
