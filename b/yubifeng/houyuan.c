inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @long
����ׯ��ƽʱ�����ĵط�������������壬������ݲ�����
ֻ�м��ò���ͦ�������Ժ����һ��ʯ���ͼ���ʯ�ʡ�
long );
        set("exits", ([
                "north"    : __DIR__"houting",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}