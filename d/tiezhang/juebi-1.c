inherit ROOM;

void create()
{
        set("short", "�ͱ�");
        set("long", @LONG
���ߵ��������ǰ���Ѿ�û��·�ˡ�����ǰ��һ��������ɽ�壬����
���ƣ���������ͷ��ʯ���������źܶ����������紵����ɳɳ���졣
LONG    );
        set("exits", ([
                "southwest" : __DIR__"shangu-2",
                "northup" : __DIR__"szfeng",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "tiezhang");
        setup();
}