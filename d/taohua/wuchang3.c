inherit ROOM;

void create()
{
        set("short", "���г�");
        set("long", @LONG
�������һ�����ָɽׯ���еĳ������󲿷ֵ��һ�������
�书����һ���ĸ����Ժ����������ޣ������ϳ���ѧ��
LONG);
        set("exits", ([
                "north" : __DIR__"houyuan",
        ]));
        set("outdoors", "taohua");
        set("for_family", "�һ���");
        setup();
        replace_program(ROOM);
}
