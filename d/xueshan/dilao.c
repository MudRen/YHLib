inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǵ������ڵ�һ����������ʪ���η�����е���ֵ�
������᲻ʱ����һ�����ȴ��ôҲ�Ҳ������ء�
LONG);
        set("exits", ([
                "southup" : __DIR__"houyuan",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
