inherit SHOP;

void create()
{
	set("short", "����ի");
	set("long", @LONG
����ի�Ǹ��ݳ��������ĵ��̣��������й��ŵ�һ���Ҷ�
��д�š�������硹�ĸ����֣�������Ȼ�𾴡���������Ļ�
����ȴ����һ��������Ѿ��ܾ�û���������ˡ�
LONG);
        set("open_long", @LONG
����ի�Ǹ��ݳ��������ĵ��̣��������й��ŵ�һ���Ҷ�
��д�š�������硹�ĸ����֣�������Ȼ�𾴡����������
���������ϰ����˸�ʽ������������Ŀ�Ļ��
LONG);
	set("no_fight", 1);
	set("no_beg", 1);
	set("owner", "VOID_SHOP");
	set("exits", ([
                "down" : "/d/fuzhou/majiu",
        ]));
	set("no_steal", 1);
	set("objects", ([
                __DIR__"waiter" : 1,
        ]));
	set("no_clean_up", 0);
	set("shop_type", 0);

	setup();
}
