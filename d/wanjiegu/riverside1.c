inherit ROOM;

void create()
{
        set("short", "����С·");
        set("long", @LONG
�������׽��ߵ�һ��С·����ˮ���ϴ����汼�ڶ�������
���ϲ�ʱ���������ĺ��������뽭��ĺ�Х���γ�һ�����˵�
�����֣����˾���Ϊ֮һ��
LONG);
        set("outdoors", "wanjiegu");
        set("exits", ([
                "northup" : __DIR__"riverside2",
        ]));
        setup();
        replace_program(ROOM);
}
