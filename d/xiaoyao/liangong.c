inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
���������е�һ��ʯ�ݣ������Ե�ʲô�徻�ͼ��ӣ�����
�в�û��ʲô�ر�İ�������������ܵ��κε�ɧ�ţ��Ǹ�
�����ڹ��ĺõط���
LONG);
        set("exits", ([
                "south" : __DIR__"xiaodao4",
        ]));

        set("objects", ([
                CLASS_D("xiaoyao") + "/wulingj" : 1,
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
