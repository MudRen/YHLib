inherit ROOM;

void create()
{
        set("short", "��ɼ��");
        set("long", @LONG
����Ƭ������յ���ɼ�֡�����Ҳ�ϱ�����������ɼ����
��һ�飬֦��Ҷï����һ�����ɡ��������գ��������ڵ�˿
��Ҳ�ޡ������Ϻ��Ŀ�֦��Ҷ����Ȼ�οͺ���̤��˴���
LONG);
        set("exits", ([
                "southwest" : __DIR__"bashisipan3",
                "northdown" : __DIR__"lengsl3",
                "southeast" : __DIR__"jieyindian",
        ]));
        set("objects", ([
                CLASS_D("misc") + "/houwang" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
