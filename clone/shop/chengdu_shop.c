inherit SHOP;

void create()
{
	set("short", "����¥");
	set("long", @LONG
�ɶ��ų��츮֮���������ʢ������һʱ����������װ��
���£����ó������Ƿ���һ����˼�ģ���������Ļ�����ȴ��
��һ��������Ѿ��ܾ�û���������ˡ�
LONG);
        set("open_long", @LONG
�ɶ��ų��츮֮���������ʢ������һʱ����Ҳ���¥��
�۸�ʽ������ϡ����Ʒ�������ڱ�����ڹ���ġ���������װ
�����£����ó������Ƿ���һ����˼�ġ�
LONG);
	set("no_fight", 1);
	set("no_beg", 1);
	set("owner", "VOID_SHOP");
	set("exits", ([
                "down" : "/d/city3/majiu",
        ]));
	set("no_steal", 1);
	set("objects", ([
                __DIR__"waiter" : 1,
        ]));
	set("no_clean_up", 0);
	set("shop_type", 0);

	setup();
}
