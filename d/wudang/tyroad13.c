inherit ROOM;

void create()
{           
        set("short", "��԰");
        set("long", @LONG
��ǰ��Ȼ���ʣ������ɵ�������԰��С·�ϡ�����������
�֣�����ʢ���ŷۺ���һ�������һƬ���������ߡ���ʱ����
�䡸���ˡ��طɹ�����ʧ���ڻ����У���ֻ���������ϻ���׷
���ţ�ߴߴ�������������ӡ�Զ���Ǹ߸ߵ������塣
LONG );
        set("outdoors", "wudang");

        set("exits", ([
                "east" : __DIR__"gyroad1",
                "west" : __DIR__"tyroad12",
        ]));
        set("objects", ([
                CLASS_D("wudang") + "/shouyuan" : 1,
        ]));
        setup();
}