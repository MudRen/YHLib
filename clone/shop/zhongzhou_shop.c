inherit SHOP;

void create()
{
	set("short", "�ٺ�ի");
	set("long", @LONG
���������ݳ����������ĵ��̣���������װ�޵��൱����
���£���ľ�̵أ����ŵ񴰣��������й���һ���ٺ�ͼ������
����Ļ�����ȴ����һ������Ѻܾ�û�˴����ˡ�
LONG);
        set("open_long", @LONG
���������ݳ����������ĵ��̣���������װ�޵��൱����
���£���ľ�̵أ����ŵ񴰣��������й���һ���ٺ�ͼ������
��Ļ�����к��ſ��ˣ�æ����ͷ�󺹡�
LONG);
	set("no_fight", 1);
	set("no_beg", 1);
	set("owner", "VOID_SHOP");
	set("exits", ([
                "down" : "/d/zhongzhou/majiu",
        ]));
	set("no_steal", 1);
	set("objects", ([
                __DIR__"waiter" : 1,
        ]));
	set("no_clean_up", 0);
	set("shop_type", 0);

	setup();
}
