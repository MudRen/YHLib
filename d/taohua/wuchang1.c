inherit ROOM;

void create()
{
        set("short", "���г�");
        set("long", @LONG
�������һ�����ָɽׯ���еĳ������󲿷ֵ��һ�������
�书����һ���ĸ����Ժ����������ޣ������ϳ���ѧ��
LONG);
        set("exits", ([
                "northwest" : __DIR__"houyuan",
        ]));

        set("for_family", "�һ���");
        set("outdoors", "taohua");
        setup();
        replace_program(ROOM);
}
