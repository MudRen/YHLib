inherit ROOM;

void create()
{
        set("short", "���۱���");
        set("long", @LONG
�����ż�ʯͷ̨�ף�������Ƿ��������������ͺ����⡣
�ߴ�ķ��񼸺��������ݶ���������Ȼ�������������ŵĵط�
���ż��Ź�����������ʱ�ʵĹϹ����������ߵĴ�������˻�
�ߡ�������ʮ���޺���
LONG);
        set("objects", ([
  		__DIR__"npc/obj/rulaixiang" : 1,
	]));

        set("no_clean_up", 0);
        set("exits", ([
  		"south" : __DIR__"zhongyuan",
  		"north" : __DIR__"houyuan",
	]));

        setup();
        replace_program(ROOM);
}
