/*

����Ӧ�� perform �ļ�����ϣ�

#include "/kungfu/skill/eff_msg.h";

        int p;

        p = (int)target->query("qi") * 100 / (int)target->query("max_qi");

        msg += "( $n" + eff_status_msg(p) + " )\n";
*/

string eff_status_msg(int ratio)
{
        if (ratio==100) return HIG "����������������һ��Ҳ���ۡ�" NOR;
        if (ratio > 95) return HIG "�ƺ���Щƣ����������Ȼʮ���л�����" NOR;
        if (ratio > 90) return HIY "������������Щ���ˡ�" NOR;
        if (ratio > 80) return HIY "�����ƺ��е㲻̫��⣬����Ȼ�������ɡ�" NOR;
        if (ratio > 65) return HIY "�������꣬������״������̫�á�" NOR;
        if (ratio > 50) return HIR "�ƺ�ʮ��ƣ����������Ҫ�ú���Ϣ�ˡ�" NOR;
        if (ratio > 40) return HIR "�м���Ȼɢ�ң�������֧����������ȥ��" NOR;
        if (ratio > 30) return HIR "�������Ѿ����������ˡ�" NOR;
        if (ratio > 15) return RED "����бб��վ��վ�����ȣ��ۿ���Ҫ���ء�" NOR;
        return RED "�Ѿ���������״̬����ʱ������ˤ����ȥ��" NOR;
}
