inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������Ƕ�ׯ���ڰ��ӵ������ˣ�����������ʯ�ʣ�һ��ʯ����
ʯ�����úڰ��ӵ�ָ�������ݺ�žŰ�ʮһ����������˼򵥵ķ���
�����������ɵ������⣬ʲô��û�У�������˫������ʱ���ġ�ֻ��
�����ڶ�ׯ����֪��������ȥ�ˣ�ֻʣ��һ���������������
LONG
        );
        set("exits", ([
                "east" : __DIR__"zoulang2",
        ]));

        set("objects", ([
                __DIR__"obj/qizi" : 1,
                __DIR__"obj/qipan" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
