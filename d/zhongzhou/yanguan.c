inherit ROOM;

void create()
{
        set("short", "ѻƬ��");
        set("long", @LONG
һ��¥���߽�һ��������ԭ��������һ��ѻƬ�ݡ�������
�Ŵ�Լ�м�ʮ�����Σ������̹����������ϣ��Ա߻���С
�������ѻ�ݡ����濿ǽ���������Ρ�
LONG);
       set("exits", ([
                "up" : __DIR__"chalou",
                "east" : __DIR__"danjian",

       ]));
       setup();
}
