inherit ROOM;

void create()
{
        set("short", "��ի��");
        set("long", @LONG
��ի���ļ��������յ���������ɫ���������Ҷ�����һ��
���ż�������ɲ񣬺����Ǻ����ޣ�˵�������ֲ������ķ�
�˲�ȥ����һ�ߵ����ϰ���һ����Ͱ�������и�С�ų�ȥ��
LONG);
        set("objects", ([
  		__DIR__"npc/suzhai.c" : 1,
  		__DIR__"npc/shaohuo" : 1,
	]));

        set("no_clean_up", 0);
        set("exits", ([
  		"south" : __DIR__"chufang",
  		"east" : __DIR__"zoulang",
	]));

        setup();
        replace_program(ROOM);
}
