inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
������һ�������ϣ���Լ�����������ߴ������������ƺ�
������������������������һ���ţ������������š��ϱ��Ǽ�
�������͵����ӣ�ʮ�ֵ����ţ�����Ʈ��һ����Ĳ��㣬����
����ϸ��ز�֪˵��Щʲô������Ů����Ц��������
LONG);

    	set("exits", ([
                "south" : __DIR__"chashi",
                "north" : __DIR__"xiuxishi",
                "west"  : __DIR__"donglang1",
                "east"  : __DIR__"liangongfang",
        ]));
        setup();
}