inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����������ɵ����ò͵ĵط��������쳤�վã�ǽ�ڶ���
��Ѭ���ˡ�������ż������Σ���λ�����ɵĵ������������
�Դ�ȣ��оƲ�ȭ��
LONG);

        set("exits", ([
                "west" : __DIR__"liangong",
                "northwest" : __DIR__"xiuxishi",
        ]));

        set("objects",([
                __DIR__"npc/puren" : 1,
                __DIR__"obj/rice" : 2,
                __DIR__"obj/xiangcha" : 1,
                __DIR__"obj/kaoya" : 1,
        ]));

        set("no_fight", 1);

        setup();
        replace_program(ROOM);
}