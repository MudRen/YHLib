inherit ROOM;

string look_gaoshi();

void create()
{
        set("short", "��������");
        set("long", @LONG
�������ݳǵ��ϳ��ţ���������Ļ���������������
��ɳ��ʴ�Ե���Щ�ưܡ��������Ϸ�����ǿǿ�����ϳ�������
�����֣���ǽ�����ż���ͨ����ʾ(gaoshi)��������߽�����
�����ﷸ�������������ӻ���ԭ���ٱ��ǽ䱸ɭ�ϣ���������
��ס���˽������ʡ�һ����ֱ����ʯ������ϱ��������졣��
���ǽ��⣬һЩ�����������˶���������ǡ���౾����Ҳ��
�����ڴ����ﾭ����������ȥ�����Լ��ֵĹϹ������������
����Ʒ�������ǳ��
LONG);
        set("outdoors", "lanzhou");
        set("item_desc", ([
                "gaoshi" : (: look_gaoshi :),
        ]));

        set("exits", ([
                "south" : __DIR__"caroad1",
                "north" : __DIR__"nandajie2",
        ]));
        set("objects", ([
                "/d/city/npc/bing" : 4,
                "/d/beijing/npc/ducha" : 1,
                "/clone/npc/walker" : 1,
        ]));
        setup();
        replace_program(ROOM);
}

string look_gaoshi()
{
        return FINGER_D->get_killer() + "\n         ����֪��\n                     Ү��Ѳ\n";
}
