inherit ROOM;

void create()
{
        set("short", "�ܵ�");
        set("long", @LONG
�������嶾�̻�԰�����һ����խ�İ�������ɭ���£���
�������˻ҳ���������������Ҳ��֪��ͨ���δ���
LONG);
        set("exits", ([
                "east" : __DIR__"midao",
                "west" : __DIR__"midao3",
        ]));
        setup();
        replace_program(ROOM);
}
