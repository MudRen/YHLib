inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������̨�����¾��Ǵ���ˡ�̨��������һ��С���ӣ���
���ð�ʯΧ�������ˡ����ߵĳر��ϡ������ء�������Ϳ����
��ɫ�����ڳص�һ�߿����ֵ���������������ƾ٣��������
�˰�����£�ȴ��ȥ�ܿ�������Ӱ������Ǳ���������Ƥ����
������������ҹ�ˡ�
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"east" : __DIR__"qianshou",
  		"westdown" : __DIR__"wroad",
	]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
        set("outdoors", "kaifeng");

        setup();
        replace_program(ROOM);
}
