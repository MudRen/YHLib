inherit ROOM;

void create()
{
        set("short", "�ܵ�");
        set("long", @LONG
�������嶾�̻�԰�����һ����խ�İ�������ɭ���£���
�������˻ҳ���������������Ҳ��֪��ͨ���δ���
LONG);
        set("exits", ([
                "south" : __DIR__"midao4",
                "up"    : "/d/city/ma_chufang",
        ]));
        setup();
        replace_program(ROOM);
}

