// Room: xiuxishi.c ��Ϣ��
// By rcwiz

inherit ROOM;

void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
��������ڤ���е�һ��é���ݣ���ƽʱ��Ϣ֮�á��˴���
Ȼ��ª�˵㣬��Ҳ���㾰ɫ���ˣ���֮�������Է�����һ����
�����׵ĸо���
LONG );
        set("no_clean_up", 0);
        set("sleep_room", 1);
        set("no_fight", 1);

        set("exits", ([
                "out" : __DIR__"xuanminggu",
        ]));
        setup();
        replace_program(ROOM);
}



