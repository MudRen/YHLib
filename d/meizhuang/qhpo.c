// qhpo.c
inherit ROOM;

void create()
{
        set("short", "�滱��");
        set("long", @LONG
��������滱���ˣ��������Ŵ��СС��ǧ��ٹֵĻ������е�
����һֱ���죬�е����������ƣ������������ԼԼ����һ�������
�����������ޣ��������֡�
LONG
        );
        set("outdoors", "meizhuang");
        set("exits", ([
            "eastup" : __DIR__"xiaodao",
            "west"  : __DIR__"senlin2",
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
