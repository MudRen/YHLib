inherit ROOM;

void create()
{
        set("short", "�Ƶ�");
        set("long", @LONG
������һ�Ҷ�����ɫ�ľƵ꣬���ڵش�����ɽ�£��Ƶ��
�Թ�Ӧ��ζʳƷ�������ԭ���Ͷ����������ʣ����ԾƵ�����
��¡���Ƶ껹��Ӫ��ɢװ�Ƶ�ҵ��
LONG);
        set("exits", ([
                "north" : __DIR__"xijie",
        ]));
        set("objects",([
                "/d/city/npc/xiaoer2" : 1,
        ]));
        set("resource/water", 1);
        setup();
        replace_program(ROOM);
}
