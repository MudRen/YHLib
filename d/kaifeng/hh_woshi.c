inherit ROOM;

void create()
{
        set("short", "�ܶ�������");
        set("long", @LONG
�����Ǻ컨���ܶ����ľ���֮����ӭ��һ��ɽˮ��������
�ף����������ֱʣ�������һ����ҡ�С���ϵ�һ����֬��ƿ
���������Ķ��Ǿ�Ө��͸�İ׾գ���֪������˸���¯����
��һ���������޵İ��㣬������Ƣ��
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"south" : __DIR__"hh_xiaojing2",
	]));
        set("objects", ([
                CLASS_D("honghua") + "/chen" : 1,
                __DIR__"npc/xinyan" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
